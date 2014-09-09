#def lineType(line):
#	if (line.len > 0):
#		lineValue = 0;
#		return lineValue

def codeIsMadeOf(line, char):
	return (line != '') and (line.count(char) == len(line))

def headerDashes(line):
	return (line != '') and (line[0] == '-' or line[0] == '=')