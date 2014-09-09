import os
import string
import sys
from findLineType import codeIsMadeOf, headerDashes

def nextLineComposedOf(possibleUnderlineString, char):
	return ((possibleUnderlineString != '') and (possibleUnderlineString.count(char) == len(possibleUnderlineString)))

def main():
	inFilePath = sys.argv[1]
	parser = markdownConverter()

	#cin file from console as read file
	with open(inFilePath, 'r') as inFile:
		parser.parseFile(inFile)

	#cout file as a written html file (sample.html).
	with open(outFilePath, 'w') as outFile:
		parser.writeToFile(outFile)

#initialize main
if __name__ == '__main__':
	main()