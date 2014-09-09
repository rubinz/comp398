from helperFunction import codeIsMadeOf, headerDashes

import re

class ElementType(object): 
	header1 = 1
	header2 = 2
	paragraph = 3 

clas(object):
	def __init__(self, elementType=None, lineString=None, lineNumber=None):
		self.type = elementType
		self.lineString = lineString
		self.lineNumber = lineNumber
		self.text = None

	def changeToHtml(self, string):
		tempText = string

		splitString = [el for el in re.split(r'\*\*|__', tempText) if el != '']

		tempText = ''

		i = 0
		while i + 2 < len(splitString):
			tempText += splitString[i] + '<strong>' + splitString[i+1] + '</strong>'

			i = i + 2

		tempText += splitString[-1]

		splitString = [el for el in re.split(r'\*|_', tempText) if el != '']

		tempText = ''

		i = 0
		while i + 2 < len(splitString):
			tempText += splitString[i] + '<em>' + splitString[i+1] + '</em>'

			i = i + 2

		tempText += splitString[-1]

		self.text = tempText;

	def __str__(self):
		if self.type == None:
			return ''

		tag = ''

		if self.type == ElementType.paragraph:
			tag = 'p'

		elif self.type == ElementType.header1:
			tag = 'h1'
		elif self.type == ElementType.header2:
			tag = 'h2'
		return '<' + tag + '>' + str(self.text) + '</' + tag + '>'

class MarkdownParser(object):
	def __init__(self):
		self.elements = []

	def identify(self, lineString):
		if lineString == '':
			lineType = None
		elif lineString.startswith('##'):
			lineType = ElementType.header2
		elif lineString.startswith('#'):
			lineType = ElementType.header1
		else:
			lineType = ElementType.paragraph
		return lineType

	def handle(self, lineType, lineIndex):
		line = self.lines[lineIndex]

		newElement = codeType(elementType=lineType)

		if (lineType == ElementType.header1 or 
			lineType == ElementType.header2:
			newElement.changeToHtml(line.lstrip('#').lstrip())

			string = line
			while (lineIndex + 1 < len(self.lines)) and (self.identify(self.lines[lineIndex + 1]) == ElementType.paragraph):
				string += ('\n' + self.lines[lineIndex + 1])
				lineIndex += 1

			newElement.changeToHtml(string)

		self.elements.append(newElement)

		return lineIndex + 1

	def setLines(self):
		currentlyIn = None
		i = 0
		while i < len(self.lines):
			lineType = self.identify(self.lines[i])
			i = self.handle(lineType, i)

	def setFile(self, fileObj):
		if isinstance(fileObj, file):
			fileObj = fileObj.read()

		self.lines = fileObj.split('\n')

		self.parseLines()

	def outputFile(self, fileObj):
		for element in self.elements:
			fileObj.write(str(element))
			fileObj.write('\n')