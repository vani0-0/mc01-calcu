MC01 - Calculator

PRECEDENCE OF OPERATORS 

| Operators | Priority |
|:---------:|:--------:|
| ^ | 1 |
| * and / | 2 |
| + and - | 3 |

Infix Notation: 
- The operators are written in between their operands

Postfix Notation:
- The operaetors are written after their operands.
- The order of evaluation of operation is left to write with no brackets in the expression to change the order

Using Stack to convert infix to postfix 

Algorithm
Scan symbol from left to right and for each symbol, do the following:
- If sysmbol is an operand:
-- Print Symbol on to screen
- If symbol is a left parenthesis
-- Push it on the stack
- If symbol is a right parenthesis
-- Pop all the operators from the stack upto the first left parenthesis, and print on the screen
-- Discard left and right parenthesis
- If symbol is an operator 
-- If the precederence of the operator in the stack are greater than or equal to the current oprator, then pop the operator out of the stack and print them of the screen and push the current operator on to the stack
-- else push the current operator on to the stack

7+5*3/5^1+(3-2)
Output: 	753*51^/+32-+

8*(5^4+2)-6^2/(9*3)
Output:		8542+^*62^93*/-

Evalutating Postfix expression
Scan the symbols of the given postfix expression from left to right and for each symbol, do the following:
- If symbol is an operand
-- Push it on the stack.
- If symbol is an operator
-- Pop two symbols out of the stack and apply the operator on these symbols.
-- Push the result on the stack
- After scanning all the symbols of the postfix expression, pop the remaining symbol out of the stack and print it on the screen. The remaining symbol is the result obtained after evaluating the postfix expression.
