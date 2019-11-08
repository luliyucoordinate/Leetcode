#!/usr/bin/python3
import os, bisect

# 题目名称
name = "Most Profit Assigning Work"
ID = 826
url = "https://leetcode.com/problems/most-profit-assigning-work/"
difficult = "Medium"
prog = ['c', 'cpp', 'py', 'go', 'js', 'java']


# 创建题目文件夹和文件
ID = "{0:04}".format(ID)
dirName =  "-".join([ID] + name.split(" "))
if not os.path.exists(dirName):
    os.makedirs(dirName)
    for p in prog[1:]:
        fileName = './' + dirName + '/' + ID + '.' + p
        with open(fileName, 'w') as f:
            pass

# 在readme文件中添加题目
with open("../README.md") as f:
    data = f.readlines()

tData = data[6:]
insertData = [ID, '[' + name + ']' + '(' + url + ')', 'c']
for p in prog[1:]:
    fileName = './src/' + dirName + '/' + ID + '.' + p
    if p == 'cpp':
        p = 'c++'
    elif p == 'py':
        p = 'python'
    insertData.append('[' + p + ']' + '(' + fileName + ')')

insertData.append(difficult)
insertData = '|' + '|'.join(insertData) + '|'
index = bisect.bisect(tData, insertData)
if index == len(tData):
    insertData = '\n' + insertData
else:
    insertData += '\n'

tData.insert(index, insertData)
with open("../README.md", 'w') as f:
    f.writelines(data[:6] + tData)
        