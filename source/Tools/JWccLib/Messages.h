#pragma once

#include <string>
#include <vector>
#include <memory>

using namespace std;

namespace WadeSpace
{
	enum MessageType
	{
		FATAL_ERROR,
		ERROR,
		WARNING,
		INFO
	};
	struct Message
	{
		MessageType type;
		string message;
	};
	class Messages
	{
		shared_ptr<vector<Message>> messages;
	public:
		Messages() { messages = make_shared<vector<Message>>(); }
		Messages(const Messages& other) = default;
		virtual ~Messages() = default;
		Messages(Messages&& other) noexcept = default;
		Messages& operator=(const Messages& other) = default;
		Messages& operator=(Messages&& other) noexcept = default;
		[[nodiscard]] shared_ptr<vector<Message>> getMessages() const { return messages; }
		void setMessages(shared_ptr<vector<Message>> msgs) { messages = msgs; }
		[[nodiscard]] bool hasMessages() const { return messages != nullptr; }
		void addMessage(MessageType type, string message) { messages->push_back({type, message}); }
	};
}
