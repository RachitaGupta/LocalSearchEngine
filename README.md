# LocalSearchEngine
Client Server architecture implemented
The client sends a connection request to the server. The connection status is sent back by the server. An already existing user will be asked to login with the login details, else if it’s a new user then the user is will be first registered and then asked to login. 

Once the user is authenticated, he/she will be provided with an option to send a .c file or an already available executable file. In case of either of the files, the file will first be encrypted and sent to the server. The server decrypts the same and detects if the received file is a .c or an executable file. In case of a .c file the file is first compiled. Upon successful compilation and creation of an executable file, the executable is run and the output is sent back to the client. If the compilation is unsuccessful then the errors are sent to the client.

The data sent from the server to client (either the output results or the compilation errors) is received on the client side and displayed to the user. Along with the output the original file that was sent by the user is sent back in an encrypted format. This file is received by the client, decrypted and then displayed to the user.
