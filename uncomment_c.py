# 去掉C语言的注释
def deleteComment(code):
	idx = 0;
	blockCommonIdx = 0
	lineCommonIdx = 0
	while True:
		blockCommonIdx = code.find("/*", idx)
		lineCommonIdx = code.find("//", idx)
		if blockCommonIdx == -1 and lineCommonIdx == -1:
			break
		# no line comment
		if lineCommonIdx == -1:
			blockCommonEnd = code.find("*/", blockCommonIdx + 1)
			code = code[:blockCommonIdx] + code [blockCommonEnd + 2:]
			idx = blockCommonIdx
		# no block comment
		elif blockCommonIdx == -1:
			lineCommonEnd = code.find("\n", lineCommonIdx + 1)
			if lineCommonEnd != -1:
				code = code[:lineCommonIdx] + code [lineCommonEnd:]
			else:
				code = code[:lineCommonIdx]
			idx = lineCommonIdx
		# block comment before line comment
		elif blockCommonIdx < lineCommonIdx:
			blockCommonEnd = code.find("*/", blockCommonIdx + 1)
			code = code[:blockCommonIdx] + code [blockCommonEnd + 2:]
			idx = blockCommonIdx
		# line comment before block comment
		else :
			lineCommonEnd = code.find("\n", lineCommonIdx + 1)
			if lineCommonEnd != -1:
				code = code[:lineCommonIdx] + code [lineCommonEnd:]
			else:
				code = code[:lineCommonIdx]
			idx = lineCommonIdx
	return code
