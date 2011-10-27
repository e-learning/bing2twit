#!/usr/bin/python2.4

'''
Created on 26.10.2011

@author: renoire
'''

import twitter

def main():
  
    consumer_key = '6sN3SUkLLliipOwSU3RYNw'
    consumer_secret = '4wjLBdXFLTmxc2Jlmnr4MfNNbnlOU4dAwc7I945qtTg'
    access_key = '38480981-pOfD012d4WbaqcncgZ4eW4br071TlHTIvyntcxHbh'
    access_secret = '4e2ljc0jLqwK6fxypk38Lt04Clw1H9fZAXKX8'
  
    api = twitter.Api(consumer_key=consumer_key, consumer_secret=consumer_secret,
                    access_token_key=access_key, access_token_secret=access_secret)

    api.PostUpdate("Hello world!")

if __name__ == "__main__":
    main()
