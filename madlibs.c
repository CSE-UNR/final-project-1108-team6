// Authors: Keira Wallace, Azure Samara, William Ward
// Date: 12/3/2024
// Purpose: Final Group Project

#include <stdio.h>

#define STR_CAP 500

int readFile(FILE *readPtr, char readStr[], char output[][STR_CAP], char input[][STR_CAP]);
int nextPunctuation(int nextLine, char text[][STR_CAP]);
void readFirstLetter(int lines, char output2[][STR_CAP], char input2[][STR_CAP]);
void get2DInput(int inputIndex2, char userInput2[][STR_CAP], char inputType2[]);
int stringLength(const char str[]);
void stringCopy(const char string1[], char string2[]);

int main(int argc, char *argv[]){
	FILE *filePtr;
	char fileStr[STR_CAP];
	char outputText[STR_CAP][STR_CAP];
	char inputText[STR_CAP][STR_CAP];
	
	if(argc < 2){
		printf("Please include file name as second argument.\n");
		return 0;
	}
	
	filePtr = fopen(argv[1], "r");
	if(filePtr == NULL){
		printf("Couldn't open \"%s\".\n", argv[1]);
		return 0;
	}
	
	int fileLines = readFile(filePtr, fileStr, outputText, inputText);
	
	for(int lineIndex = 0; lineIndex < fileLines; lineIndex++){
		if(nextPunctuation(lineIndex + 1, outputText) == 1){
			printf("%s", outputText[lineIndex]);
		}
		else{
			printf("%s ", outputText[lineIndex]);
		}
	}
	
	printf("\n");
	
	return 0;
}

int readFile(FILE *readPtr, char readStr[], char output[][STR_CAP], char input[][STR_CAP]){
	int readIndex = 0, readLines = 0, outputIndex;
	
	while(fscanf(readPtr, "%c", &readStr[readIndex]) == 1){
		if(readStr[readIndex] == '\n'){		
			if(output[readLines][0] == 'A' || output[readLines][0] == 'V' || output[readLines][0] == 'N'){
				readFirstLetter(readLines, output, input);
			}
			readLines++;
			outputIndex = 0;
		}
		else{
			output[readLines][outputIndex] = readStr[readIndex];
			outputIndex++;
		}
		readIndex++;
	}
	
	return readLines;
}

int nextPunctuation(int nextLine, char text[][STR_CAP]){
	switch(text[nextLine][0]){
		case ',':
			return 1;
		case '.':
			return 1;
		case '/':
			return 1;
		case '?':
			return 1;
		case ';':
			return 1;
		case ':':
			return 1;
		case '!':
			return 1;
		case '-':
			return 1;
		return 0;
	}
}

void readFirstLetter(int lines, char output2[][STR_CAP], char input2[][STR_CAP]){
	switch(output2[lines][0]){
		case 'A':
			get2DInput(lines, input2, "Please enter an adjective: ");
			break;
		case 'V':
			get2DInput(lines, input2, "Please enter a verb: ");
			break;
		case 'N':
			get2DInput(lines, input2, "Please enter a noun: ");
			break;
	}
	stringCopy(input2[lines], output2[lines]);
}

void get2DInput(int inputIndex2, char userInput2[][STR_CAP], char inputText2[]){
	printf("%s", inputText2);
	fgets(userInput2[inputIndex2], STR_CAP, stdin);
	userInput2[inputIndex2][stringLength(userInput2[inputIndex2]) - 1] = '\0';
}

int stringLength(const char str[]){
	int length = 0;
	
	for(int lenIndex = 0; str[lenIndex] != '\0'; lenIndex++){
		length++;
	}
	
	return length;
}

void stringCopy(const char string1[], char string2[]){
	int string1Length = stringLength(string1);	
	
	for(int copyIndex = 0; copyIndex < string1Length; copyIndex++){
		string2[copyIndex] = string1[copyIndex];
	}
	
	string2[string1Length] = '\0';
}
