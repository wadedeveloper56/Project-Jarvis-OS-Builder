#pragma once

using namespace std;

namespace WadeSpace
{
	class ExpressionTree;

	class Initializer
	{
		ExpressionTree* assignmentExpression;
		vector<Initializer*>* initializerList;
	public:
		Initializer() = default;
		Initializer(ExpressionTree* assignmentExpression);
		Initializer(vector<Initializer*>* initializerList);
		virtual ~Initializer() = default;
		Initializer(Initializer&& other) noexcept = default;
		Initializer(const Initializer& other) = default;
		Initializer& operator=(const Initializer& other) = default;
		Initializer& operator=(Initializer&& other) noexcept = default;
		[[nodiscard]] ExpressionTree* getAssignmentExpression() const { return assignmentExpression; }
		[[nodiscard]] bool hasAssignmentExpression() const { return assignmentExpression != nullptr; }
		[[nodiscard]] vector<Initializer*>* getInitializerList() const { return initializerList; }
		[[nodiscard]] bool hasInitializerList() const { return initializerList != nullptr; }
		void setAssignmentExpression(ExpressionTree* assignmentExpression) { this->assignmentExpression = assignmentExpression; }
		void setInitializerList(vector<Initializer*>* initializerList) { this->initializerList = initializerList; }
		void addInitializer(Initializer* initializer)
		{
			if (!initializerList)
			{
				initializerList = new vector<Initializer*>();
			}
			initializerList->push_back(initializer);
		}
	};
}
