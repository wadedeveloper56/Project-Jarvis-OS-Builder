#pragma once

using namespace std;

namespace WadeSpace
{
	class Expression;

	class Initializer
	{
	public:
		Initializer();
		Initializer(Expression* assignmentExpression);
		Initializer(vector<Initializer*>* initializerList);
		virtual ~Initializer();

		Initializer(Initializer&& other) noexcept;
		Initializer(const Initializer& other);
		Initializer& operator=(const Initializer& other);
		Initializer& operator=(Initializer&& other) noexcept;

		[[nodiscard]] Expression* getAssignmentExpression() const;
		[[nodiscard]] vector<Initializer*>* getInitializerList() const;

		[[nodiscard]] bool hasAssignmentExpression() const;
		[[nodiscard]] bool hasInitializerList() const;

	private:
		Expression* assignmentExpression;
		vector<Initializer*>* initializerList;
	};
}
