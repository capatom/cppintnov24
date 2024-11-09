from pathlib import Path
import sys

def getArgs():
    if len(sys.argv) == 3:
        return  sys.argv[1], sys.argv[2] 
    else:
        args = ['']
        while len(args) < 2:
            newArgs = input(f'From-pattern {args[0]}, To-pattern : ').split()
            if len(newArgs) == 1:
                if args[0] == '':
                    args[0] = newArgs[0]
                else:
                    args.append(newArgs[0])
            elif len(newArgs) == 2:
                args = newArgs
        return args
    #return  'T04.','T04.'


def getFiles(from_pattern):
    folder = Path.cwd()
    fileList = list(folder.glob(f'*{from_pattern}*.*'))
    for file in fileList:
        if file.suffix not in ('.cpp, .h'):
            fileList.remove(file)
    
    return fileList

def renameFiles(fileList, from_pattern, to_pattern):
    for file in fileList:
        newName = file.stem
        newName = newName.replace(from_pattern, to_pattern) + file.suffix
        print(f'From {file.name} to {newName}')
        file.rename(newName)

def main():
    from_pattern, to_pattern =  getArgs()
    fileList = getFiles(from_pattern)
    renameFiles(fileList,from_pattern, to_pattern)

main()