class Vstr(str): 
    def __iter__(self): 
        special_set = 'abcdefghijklmnV2EX' 
        special_str = '' 
        for i in super().__iter__(): 
            if i in special_set: 
                special_str += i 
            else: 
                if special_str: 
                    yield special_str 
                special_str = '' 
                yield i 


mystr = Vstr('为了让 abc 在 V2EX 上的 egg222 时间更有效率') 
for i in mystr: 
    print(i)