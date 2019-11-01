with open("README.md") as f:
    data = f.readlines()

with open("new.md", 'w') as f:
    for i, l in enumerate(data):
        if i < 6:
            continue
        sl = l.split('|')
        sl.insert(len(sl) - 2, " ")
        f.write("|".join(sl))
