"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
class MiddlewareProtocol {
    constructor(logger, lldbSocket, vscodeSocket) {
        this.logger = logger;
        this.lldbSocket = lldbSocket;
        this.vscodeSocket = vscodeSocket;
    }
    // private sendFailureToVSCode() {
    //   const object = {
    //     body: {
    //       exitCode: 9,
    //       event: "terminated",
    //       seq: 0,
    //       type: "event"
    //     }
    //   };
    //   const j = JSON.stringify(object);
    //   this.vscodeSocket.write(
    //     `Content-Length: ${Buffer.byteLength(j, "utf8")}\r\n\r\n$j}`,
    //     "utf8"
    //   );
    // }
    sendToLLDBSocket(message) {
        const json = JSON.stringify(message);
        this.logger.appendLine(`[---------vscode]]:\n${json}`);
        this.lldbSocket.write(`Content-Length: ${Buffer.byteLength(json, "utf8")}\r\n\r\n${json}`, "utf8");
    }
    handleInitilizeRequest(message) {
        message.arguments.supportsCommandInterpreter = true;
        this.sendToLLDBSocket(message);
    }
    handleLaunchRequest(message) {
        this.sendToLLDBSocket(message);
    }
    handleVSCodeRequest(message) {
        if (message.command === "initialize") {
            this.handleInitilizeRequest(message);
        }
        else if (message.command === "launch") {
            this.handleLaunchRequest(message);
        }
        else if (message.command === "disconnect") {
            message.arguments.terminateDebuggee = true;
            this.sendToLLDBSocket(message);
        }
        else if (message.command === "attach") {
            if (message.arguments.attachCommands === undefined ||
                message.arguments.attachCommands.length === 0) {
                const root = vscode.extensions.getExtension("lanza.lldb-vscode")
                    .extensionPath;
                message.arguments.attachCommands = [
                    "command script import " + root + "/sleep.py"
                ];
                message.arguments.stopOnEntry = true;
            }
            this.sendToLLDBSocket(message);
        }
        else {
            this.sendToLLDBSocket(message);
        }
    }
    start() {
        let rawData = new Buffer(0);
        let contentLength = -1;
        this.vscodeSocket.on("data", data => {
            this.logger.appendLine("[from vscode] " + data);
            rawData = Buffer.concat([rawData, data]);
            while (true) {
                if (contentLength >= 0) {
                    if (rawData.length >= contentLength) {
                        const message = rawData.toString("utf8", 0, contentLength);
                        rawData = rawData.slice(contentLength);
                        contentLength = -1;
                        if (message.length > 0) {
                            try {
                                let msg = JSON.parse(message);
                                this.handleVSCodeRequest(msg);
                            }
                            catch (e) {
                                // print an error
                            }
                        }
                        continue;
                    }
                }
                else {
                    const idx = rawData.indexOf("\r\n\r\n");
                    if (idx !== -1) {
                        const header = rawData.toString("utf8", 0, idx);
                        const lines = header.split("\r\n");
                        for (let i = 0; i < lines.length; i++) {
                            const pair = lines[i].split(/: +/);
                            if (pair[0] === "Content-Length") {
                                contentLength = +pair[1];
                            }
                        }
                        rawData = rawData.slice(idx + 4);
                        continue;
                    }
                }
                break;
            }
        });
        this.lldbSocket.on("data", data => {
            this.logger.appendLine("[from lldb] " + data);
            this.vscodeSocket.write(data);
        });
        // we only accept data from vscode after lldb is connected
        this.vscodeSocket.resume();
    }
}
function startCommunication(logger, lldbSocket, vscodeSocket) {
    const protocol = new MiddlewareProtocol(logger, lldbSocket, vscodeSocket);
    protocol.start();
    return protocol;
}
exports.startCommunication = startCommunication;
//# sourceMappingURL=MiddlewareProtocol.js.map