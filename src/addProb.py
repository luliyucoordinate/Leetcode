#!/usr/bin/python3
import os, bisect

# 题目名称
name = "Valid Parenthesis String"
ID = 678
url = "https://leetcode.com/problems/valid-parenthesis-string/"
difficult = "Medium"
prog = ['c', 'cpp', 'py', 'go', 'js', 'java', 'rs']


# 创建题目文件夹和文件
ID = "{0:04}".format(ID)
dirName =  "-".join([ID] + name.split(" "))
if not os.path.exists(dirName):
    os.makedirs(dirName)
    for p in prog[1:]:
    # for p in ['cpp']: # only for cpp
        fileName = './' + dirName + '/' + ID + '.' + p
        with open(fileName, 'w') as f:
            pass
        
# 在readme文件中添加题目
with open("../README.md") as f:
    data = f.readlines()

tData = data[6:]
insertData = [ID, '[' + name + ']' + '(' + url + ')', 'c']

### only for cpp ###
# fileName = './src/' + dirName + '/' + ID + '.' + 'cpp'
# insertData.append('[c++]' + '(' + fileName + ')')
# insertData += ['python'] + prog[3:]
### only for cpp ###

for p in prog[1:]:
    fileName = './src/' + dirName + '/' + ID + '.' + p
    if p == 'cpp':
        p = 'c++'
    elif p == 'py':
        p = 'python'
    elif p == 'rs':
        p = 'rust'
    insertData.append('[' + p + ']' + '(' + fileName + ')')

insertData.append(difficult)
insertData = '|' + '|'.join(insertData) + '|'
index = bisect.bisect(tData, insertData)
if index == len(tData):
    insertData = '\n' + insertData
else:
    insertData += '\n'

target_org_str, insert_org_str = tData[index-1].strip("\n")[:6], insertData.strip("\n")[:6]
if target_org_str != insert_org_str:
    tData.insert(index, insertData)
    with open("../README.md", 'w') as f:
        f.writelines(data[:6] + tData)
        