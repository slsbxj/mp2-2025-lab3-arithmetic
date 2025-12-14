// объ€вление функций и классов дл€ вычислени€ арифметических выражений

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <string>
#include <vector>
#include <map>

class ArithmeticCalculator {
public:
	ArithmeticCalculator();
	~ArithmeticCalculator();

	bool isValidExpression(const std::string& expression) const;
	std::vector<std::string> toRPN(const std::string& expression) const;
	double calculate(const std::string& expression);
	double calculateRPN(const std::vector<std::string>& rpn);
	void setVariable(const std::string& name, double value);
	double getVariable(const std::string& name) const;
	static bool isNumber(const std::string& str);
	static bool isOperator(const std::string& str);
	static bool isFunction(const std::string& str);
	static bool isVariable(const std::string& str);
	static int getPriority(const std::string& op);

private:
	std::map<std::string, double> variables;

	std::vector<std::string> tokenize(const std::string& expression) const;
	bool isUnaryMinus(const std::vector<std::string>& tokens, size_t index) const;

	double applyOperator(double a, double b, const std::string& op) const;
	double applyFunction(const std::string& func, double arg) const;
};

#endif