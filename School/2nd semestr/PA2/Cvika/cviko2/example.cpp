#include <iostream>
#include <iomanip>

using namespace std;

const int COMPLEX_WIDTH = 10;
const int COMPLEX_PRECISION = 2;

struct complex_t
{
	double re = 0;
	double im = 0;

	istream & load ( istream & in = cin );

	ostream & save ( ostream & out = cout ) const;

	complex_t minus () const
	{
		return complex_t { -re, -im };
	}

	complex_t add ( const complex_t & other ) const
	{
		return complex_t { re + other.re, im + other.im };
	}

	complex_t sub ( const complex_t & other ) const
	{
		return add( other.minus() );
	}

	complex_t mul ( const complex_t & other ) const;
};

istream & complex_t::load ( istream & in )
{
	char op, i;
	if ( !( in >> re >> op >> im >> i ) || ( op != '+' && op != '-' ) || i != 'i' ) {
		in.clear( ios::failbit );
		return in;
	}

	if ( op == '-' )
		im *= -1;

	return in;
}

ostream & complex_t::save ( ostream & out ) const
{
	return out << setfill( ' ' ) << setprecision( COMPLEX_PRECISION ) << fixed
	           << setw( COMPLEX_WIDTH ) << re
	           << ( im < 0 ? " - " : " + " )
	           << setw( COMPLEX_WIDTH ) << abs( im ) << "i";
}

complex_t complex_t::mul ( const complex_t & other ) const
{
	return complex_t {
		re * other.re - im * other.im,
		re * other.im + im * other.re
	};
}

const size_t STACK_CAPACITY = 100;

struct stack_t
{
	size_t size = 0;
	complex_t data[STACK_CAPACITY];

	bool push ( const complex_t & c );

	bool pop ();

	const complex_t & top () const
	{
		return data[ size - 1 ];
	}

	bool empty () const
	{
		return size == 0;
	}

	bool full () const
	{
		return size == STACK_CAPACITY;
	}
};

bool stack_t::push ( const complex_t & c )
{
	if ( size == STACK_CAPACITY )
		return false;
	data[ size ] = c;
	size += 1;
	return true;
}

bool stack_t::pop ()
{
	if ( size == 0 )
		return false;
	size -= 1;
	return true;
}

int main ()
{
	stack_t numbers;

	while ( !cin.eof() ) {
		char op;
		if ( !( cin >> op ) )
			break;

		if ( op == 'C' || op == 'P' || op == '+' || op == '-' || op == '*' ) {
			// OPERATION
			if ( numbers.empty() ) {
				cout << "Na zasobniku neni dostatecny pocet parametru." << endl;
				return 3;
			}
			complex_t lhs = numbers.top();

			switch ( op ) {
				case 'C':
					numbers.pop();
					break;

				case 'P':
					lhs.save( cout << "ANS: " ) << endl;
					break;

				case '+':
					numbers.pop();
					if ( numbers.empty() ) {
						cout << "Na zasobniku neni dostatecny pocet parametru." << endl;
						return 3;
					}

					{
						complex_t res = lhs.add( numbers.top() );
						numbers.pop();
						numbers.push( res );
					}

					break;

				case '-':
					numbers.pop();
					if ( numbers.empty() ) {
						cout << "Na zasobniku neni dostatecny pocet parametru." << endl;
						return 3;
					}

					{
						complex_t res = lhs.sub( numbers.top() );
						numbers.pop();
						numbers.push( res );
					}

					break;

				case '*':
					numbers.pop();
					if ( numbers.empty() ) {
						cout << "Na zasobniku neni dostatecny pocet parametru." << endl;
						return 3;
					}

					{
						complex_t res = lhs.mul( numbers.top() );
						numbers.pop();
						numbers.push( res );
					}

					break;

				default:
					cout << "Neocekavana podminka." << endl;
					return 10;
			}
		} else {
			// NUMBERS
			complex_t cpx;
			cin.putback( op );
			if ( !cpx.load( cin ) )
				break;


			if ( !numbers.push( cpx ) ) {
				cout << "Nedostatecna kapacita zasobniku." << endl;
				return 2;
			}
		}
	}

	if ( !cin.eof() ) {
		cout << "Nespravny vstup." << endl;
		return 1;
	}

	if ( !numbers.empty() ) {
		cout << "Zasobnik nebyl vyprazdnen." << endl;
	}

	return 0;
}
