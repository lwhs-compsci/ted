# plan #

The plan for the major structure of ted. 

## main ##
- print current line and prompt
- read line
- parse line into a command
- execute the command on the current buffer

## data structures ##

- buffer

	contains lines. has functions to preform text operations?maybe stuff like search, insert/delete? should commands avoid directly modifying the buffer's line data and use interface or not? also knows the current line in that buffer

- text objects

	things in a buffer like lines, line ranges, paragraphs
	should eventually be able to reference stuff like next/last regex match

- command

	represents a command
	each command has a target text object (implicitly the current line)
	each command also has an optional payload

	command syntax is layed out elsewhere

- command parser

	parses commands from lines. also has functionality to parse text objects



