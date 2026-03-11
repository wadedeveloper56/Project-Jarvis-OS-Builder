#pragma once

using namespace std;

namespace WadeSpace
{
	class ExpressionTree;

	class Initializer
	{
	public:
		Initializer();
		Initializer(ExpressionTree* assignmentExpression);
		Initializer(vector<Initializer*>* initializerList);
		virtual ~Initializer();

		Initializer(Initializer&& other) noexcept;
		Initializer(const Initializer& other);
		Initializer& operator=(const Initializer& other);
		Initializer& operator=(Initializer&& other) noexcept;

		[[nodiscard]] ExpressionTree* getAssignmentExpression() const;
		[[nodiscard]] vector<Initializer*>* getInitializerList() const;

		[[nodiscard]] bool hasAssignmentExpression() const;
		[[nodiscard]] bool hasInitializerList() const;

	private:
		ExpressionTree* assignmentExpression;
		vector<Initializer*>* initializerList;
	};
}
