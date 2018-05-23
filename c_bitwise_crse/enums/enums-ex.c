/* Enums (Enumeration constants)
 *
 * Enums can be used to create a list or set of aliases with values, you can
 * use them as macros, or pass them into functions
 */

#include <stdio.h>

// enums days {
// 	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
// };

// By default identifiers(list of names) are actually constants, are assigned 
// integer values, zero-indexed.
enum suits {
	Hearts, Diamonds, Clubs, Spades
};

enum dataSize {
	Bit = 1, Nibble =4, Byte = 8
};

void showCard(enum suits card) {
	if (card = Hearts) {
		printf("Hearts passed %d\n", card);
	} else if (card = Diamonds){
		printf("Diamonds passed %d\n", card);
	} else if (card = Clubs) {
		printf("Clubs passed %d\n", card);
	} else if (card = Spades) {
		printf("Spades passed %d\n", card);
	} else {
		printf("error\n");
	} 	
}

int main (int argc, char **argv) {
	// Creates an enum types
	enum suits playingCard;
	enum dataSize num;

	playingCard = Diamonds;
	num = Nibble;
	num = Byte;
	showCard(playingCard);
	printf("num: %d", num);
}

