from pytube import YouTube
import argparse
import os

ap = argparse.ArgumentParser()

ap.add_argument("-a", "--url", required=False,help="Youtube url")
ap.add_argument("-b", "--quality", required=False,help="video quality")
ap.add_argument("-c", "--fps", required=False,help="video fps")
ap.add_argument("-d", "--path", required=False,help="video path")
ap.add_argument("-e", "--flag", required=False,help="mp4 or mp3")

args = vars(ap.parse_args())

url = args['url']
url=url.replace("*","&")
quality = args['quality']
fps = args['fps']
path = args['path']
flag = args['flag']

yt = YouTube(url)

if flag=="0":

    try:
        yt.streams.filter(file_extension='mp4', fps=int(fps), res=quality).first().download("mp4")

    except:

        try:
            yt.streams.filter(file_extension='mp4', res=quality).first().download("mp4")

        except:
            yt.streams.filter(file_extension='mp4').first().download("mp4")


    yt.streams.filter(only_audio=True).first().download("mp3")

    for i in os.listdir("./mp3/"):
        
        mp3 = i

    for i in os.listdir("./mp4/"):

        mp4 = i

    filea = "\""+os.getcwd()+"/mp4/"+mp4+"\""
    fileb = "\""+os.getcwd()+"/mp3/"+mp3+"\""
    
    path = "\""+path+"/"+mp4+"\""
    os.system('ffmpeg -y -i {} -i {} -c:v copy -c:a aac -strict experimental {}'.format(filea, fileb, path))

    os.system("rm {}".format(filea))
    os.system("rm {}".format(fileb))

else:

    yt.streams.filter(only_audio=True).first().download("mp3")

    for i in os.listdir("./mp3/"):
        
        mp3 = i

    fileb = "\""+os.getcwd()+"/mp3/"+mp3+"\""

    temp = mp3.split(".")
    mp3 = temp[0] + ".mp3"
    path = "\""+path+"/"+mp3+"\""

    os.system("cp {} {}".format(fileb, path))
    os.system("rm {}".format(fileb))



