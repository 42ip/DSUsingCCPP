# Postfix Evaluation using Stack

- While reading the expression from left to right, push the element in the stack if it is an operand.

- Pop the two operands from the stack, if the element is an operator and then evaluate it.

- Push back the result of the evaluation. Repeat it till the end of the expression.
