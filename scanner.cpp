#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>

using namespace std;

enum tokenType {AND, BEGIN, END, FOR, IF, NOT, OR, READ, WHILE, WRITE, COMMENT, ID, REAL, STRING, 
PLUS, MULTIPLICATION, ASSIGNMENT, EQUAL, GREATERTHAN, LESSTHAN, LEFTP, COMMA, RIGHTP, SEMICOLON,
INVALID, DIVISION, INTEGER, EoF};
static char *reservedWord[] = {"AND", "BEGIN", "END", "FOR", "IF", "NOT", "OR",
				"READ", "WHILE", "WRITE"};

char tokenBuffer[80];

void skipSpaces()
{
	int ch;
	ch = cin.get();
	
	while(isspace(ch))
		ch = cin.get();
	cin.putback(ch);
}

void clear_buf(void) 
{
	for(int i = 0; i < sizeof(tokenBuffer); i++)
		tokenBuffer[i] = '\0';
}

void displayToken(tokenType code)
{
	static char message[][15] = {"AND", "BEGIN", "END", "FOR", "IF", "NOT", "OR", "READ", 	"WHILE", "WRITE", 
					"COMMENT", "ID", "REAL", "STRING", "PLUS", "MULTIPLICATION", "ASSIGNMENT", "EQUAL",
					"GREATERTHAN", "LESSTHAN", "LEFTP", "COMMA", "RIGHTP", "SEMICOLON", "INVALID","DIVISION", "INTEGER"};
	cout << message[code] << "\t\t\t" << tokenBuffer << "\n";
}



tokenType getId()
{
	tokenType code = ID;
	int   ch, i = 0;
	ch = cin.get();

	if (isalpha(ch))
	{
		tokenBuffer[i++] = ch;
		ch = cin.get();

		while (isalnum(ch))
		{
			tokenBuffer[i++] = ch;
			ch = cin.get();
		}

		cin.putback(ch);

		// look for reserved word
		int first = 0, last = 9, mid;
		bool notfound = true;
		// binary search
		while (first <= last && notfound)
		{
			mid = (first + last) / 2;
			int answer = strcmp(tokenBuffer, reservedWord[mid]);
			if (answer == 0)
				notfound = false;
			else if (answer > 0)
				first = mid + 1;
			else
				last = mid + 1;
		}
		
		if (notfound)
			code = ID;
		else
			 code = (tokenType) mid;
	}
	else			// it is not a letter
	{
		cin.putback(ch);
		code = INVALID;
	}
	return code;
}

tokenType getComment()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();
	
	if (ch == '/' && cin.peek() == '*')
	{
		tokenBuffer[i++] = ch;
		ch = cin.get();
		tokenBuffer[i++] = ch;
		ch = cin.get();
		
		while(!(ch == '*' && cin.peek() == '/') && cin.peek() != EoF)
		{
			tokenBuffer[i++] = ch;
			cin.get();
		}
		
		if (cin.peek() == EOF)
			code = INVALID;
		else
		{
			tokenBuffer[i++] = ch;
			ch = cin.get();
			tokenBuffer[i++] = ch;
			code = COMMENT;
		}
	}
	else
	{
		cin.putback(ch);
		code = INVALID;
	}

	return code;
}

tokenType getReal()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (isdigit(ch))
	{
		tokenBuffer[i++] = ch;
		ch = cin.get();
		while (isdigit(ch))
		{
			tokenBuffer[i++] = ch;
			ch = cin.get();
		}
		if (ch == '.')
		{
			tokenBuffer[i++] = ch;
			ch = cin.get();

			if (isdigit(ch))
			{
				tokenBuffer[i++] = ch;
				ch = cin.get();

				while (isdigit(ch))
				{
					tokenBuffer[i++] = ch;
					ch = cin.get();
				}
				cin.putback(ch);
				code = REAL;
			}
			else
			{
				cin.putback(ch);
				code = INVALID;
			}
		}
		else 	// not a period
		{
			cin.putback(ch);
			code = INVALID;
		}
	}
	else		// not a digit
	{
		cin.putback(ch);
		code = INVALID;
	}
	
	return code;
}

tokenType getStrings()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == '\"')
	{
		tokenBuffer[i++] = ch;		

		ch = cin.get();
		while (!(ch == '\"') && ch !=EOF)
		{
			tokenBuffer[i++] = ch;
			ch = cin.get();
		}

		if (ch == EOF)
			code = INVALID;
		else
		{
			tokenBuffer[i++] = ch;
			code = STRING;
		}
	}
	else
	{
		cin.putback(ch);
		code = INVALID;
	}

	return code;
}


tokenType getAssign()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();
	
	if (ch == ':'&&cin.peek() == '=')
	{
		tokenBuffer[i++] = ch;
		ch = cin.get();
		tokenBuffer[i++] = ch;
		return ASSIGNMENT;
	}
	else
	{
		cin.putback(ch);
		code = INVALID;
	}
}

tokenType getPlus()
{
	tokenType code;
	int ch, i = 0;
	ch = cin.get();
	
	if (ch == '+')
	{
		tokenBuffer[i++] = ch;
		code = PLUS;
	}
	else
	{
		cin.putback(ch);
		code = INVALID;
	}
	
	return code;
}

tokenType getMul()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == '*')
	{
		tokenBuffer[i++] = ch;
		return MULTIPLICATION;
	}
	else
		return INVALID;
}

tokenType getEqual()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == '=')
	{
		tokenBuffer[i++] = ch;
		return EQUAL;
	}
	else
		return INVALID;
}

tokenType getGreater()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == '>')
	{
		tokenBuffer[i++] = ch;
		return GREATERTHAN;
	}
	else
		return INVALID;
}

tokenType getLess()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == '<')
	{
		tokenBuffer[i++] = ch;
		return LESSTHAN;
	}
	else
		return INVALID;
}

tokenType getLP()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == '(')
	{
		tokenBuffer[i++] = ch;
		return LEFTP;
	}
	else
		return INVALID;
}

tokenType getRP()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == ')')
	{
		tokenBuffer[i++] = ch;
		return RIGHTP;
	}
	else
		return INVALID;
}

tokenType getComma()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == ',')
	{
		tokenBuffer[i++] = ch;
		return COMMA;
	}
	else
		return INVALID;
}

tokenType getSemiColon()
{
	tokenType code;
	int   ch, i = 0;
	ch = cin.get();

	if (ch == ';')
	{
		tokenBuffer[i++] = ch;
		return SEMICOLON;
	}
	else
		return INVALID;
}

tokenType lexical_error()
{
	tokenType code;
	int ch , i = 0;
	ch = cin.get();
	tokenBuffer[i++] = ch;
	
	code = INVALID;
	
	return code;
}

tokenType scanner()
{
	tokenType code;
	int   ch;

	skipSpaces();
	ch = cin.get();

	if (ch == EOF)
		return EoF;
	else 
	{
		cin.putback(ch);
		if (isalpha(cin.peek()))
		{
			code = getId();
			return code;
		}
		else if (cin.peek() == '/')
		{
			code = getComment();
			return code;
		}
		else if (isdigit(cin.peek()))
		{
			code = getReal();
			return code;
		}
		else if (cin.peek() == '"')
		{
			code = getStrings();
			return code;
		}
		else if (cin.peek() == '+')
		{
			code = getPlus();
			return code;
		}
		else if (cin.peek() == '*')
		{
			code = getMul();
			return code;
		}
		else if (cin.peek() == ':')
		{
			code = getAssign();
			return code;
		}
		else if (cin.peek() == '=')
		{
			code = getEqual();
			return code;
		}
		else if (cin.peek() == '>')
		{
			code = getGreater();
			return code;
		}
		else if (cin.peek() == '<')
		{
			code = getLess();
			return code;
		}
		else if (cin.peek() == ',')
		{
			code = getComma();
			return code;
		}
		else if (cin.peek() == ')')
		{
			code = getRP();
			return code;
		}
		else if (cin.peek() == '(')
		{
			code = getLP();
			return code;
		}
		else if (cin.peek() == ';')
		{
			code = getSemiColon();
			return code;
		}
		else
		{
			code = lexical_error();
		}

	}

	return code;
}

int main()
{
	int flag = 0;
	tokenType code = IF;

	while (code != EoF) 
	{
		
		clear_buf();
		code = scanner();

		if (flag == 0)
		{
			cout << "\nToken/Types\t\tWords/Lexemes\n";
			cout << "------------\t\t-------------" << endl;
			flag++;
		}
		displayToken(code);
	}
}

