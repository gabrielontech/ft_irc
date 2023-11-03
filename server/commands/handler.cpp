#include "commands.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "utils.hpp"
#include "Server.hpp"
#include "Message.hpp"
#include "messages.hpp"

#include <string>
#include <vector>
#include <iostream>

bool commandsHandler(Server &server, Client &client) {

	Message message = client.getClientMessage();

	std::cout << TEXT_GREEN << "[" << message.msg.length() << "b] " << client.getFD() << "(" << client.ID << ")" << "cmd: " << message.cmd << TEXT_RESET << std::endl;
	if (message.cmd == "PASS") {
		PASS(server, client);
	} else if (message.cmd == "PING") { // Sends a CTCP PING request to a nickname or a channel
		PING(client);
	}

	if (!client.isRegistered())
		return true;
	// past this point, the client is registered

	if (message.cmd == "NICK") { // Changes your nickname on the active server
		NICK(server, client);
	} else if (message.cmd == "USER") {

	}

	if (!client.isIdentified())
		return true;
	// past this point, the user has registered and identified

	// if (msg.cmd == "JOIN") {

	// } else if (msg.cmd == "MSG" || msg.cmd == "PRIVMSG" || msg.cmd == "NOTICE") { // DM

	// } else if (msg.cmd == "KICK") { // Removes the given nicknames from the specified channel

	// } else if (msg.cmd == "INVITE") { // Invites the specified nick to a channel.

	// } else if (msg.cmd == "TOPIC") { // Displays or modifies the topic of a channel

	// } else if (msg.cmd == "MODE") { // Modifies the user or channel modes for which you are privileged to modify
		
	// } else if (msg.cmd == "QUIT") { // Terminates the application and advertises the given message on all the networks you are connected to
		
	// } else if (msg.cmd == "PART") { // Leaves the given channels
		
	// } else if (msg.cmd == "MOTD") { // Displays the welcome message of an IRC server.
		
	// } else if (msg.cmd == "OPER") { // Grants you the IRC operator status
		
	// } 

	return true;
}