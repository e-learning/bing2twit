#!/usr/bin/python2.4

'''
Created on 26.10.2011

@author: renoire
'''

import getopt, sys
from yandex_maps import api
import twitter

def getCoord(poi):
    api_key = 'AFUErU4BAAAAtAbCNQMAfT5GKPsneqh7SGpxXzR9LT_XQfoAAAAAAAAAAAB7ZlYsxhCX1dY5oukeofQBDieS4g=='
    return api.geocode(api_key, poi)

def twiPost(coord):
    
    if coord[0]==None || coord[1]==None:
        print 'Usage: python tweet.py <here location>'
        return;

    consumer_key = '6sN3SUkLLliipOwSU3RYNw'
    consumer_secret = '4wjLBdXFLTmxc2Jlmnr4MfNNbnlOU4dAwc7I945qtTg'
    access_key = '38480981-pOfD012d4WbaqcncgZ4eW4br071TlHTIvyntcxHbh'
    access_secret = '4e2ljc0jLqwK6fxypk38Lt04Clw1H9fZAXKX8'
  
    api = twitter.Api(consumer_key=consumer_key, consumer_secret=consumer_secret,
                    access_token_key=access_key, access_token_secret=access_secret)

    api.PostUpdate("Location: " + coord[0] +" " + coord[1])

def main():
    opts, args = getopt.getopt(sys.argv[1:], 'x:v',['ix',])
    twiPost(getCoord(args[0]))
    
if __name__ == "__main__":
    main()
