import os

filelocation = input("file location (no '/' back of folder name): ")

while 1:
    videoaddress=input("video address (if you want to exit, write down 'exit'): ")

    if videoaddress=='exit':
        break
    
    videoname=input("video name: ")
    ffmpegcommand='ffmpeg -headers "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.162 Safari/537.36" -i "'+videoaddress+'" -c copy -bsf:a aac_adtstoasc "'+filelocation+'/'+videoname+'.mp4"'

    os.system(ffmpegcommand)
    #print(ffmpegcommand)