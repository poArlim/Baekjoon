import requests
import json

class truck:
    def __init__(self):
        self.p = 0
        self.load = 0

    def __str__(self):
        return str(self.p)+ ' ' + str(self.load)

    def __repr__(self):
        return '(' + str(self.p) + ' ' + str(self.load) + ')'


def getblahblah(url, headers):
    path = ''
    req = requests.get('/'.join([url,path]), headers=headers)

    j = req.json()

    for id, cnt in [(i['id'], i['located_bikes_count']) for i in j['locations']]:
        id = cnt

    return 



def main(qid=1):
    url = ''
    path = ''
    token = ''
    param = {'problem':qid}
    headers = {'X-Auth-Token':token, 'Content-Type': 'application/json'}

    req = requests.post('/'.join([url,path]), headers=headers, data=json.dumps(param))
    j = req.json()
    auth_key = j['auth_key']
    headers = {'Authorization': auth_key, 'Content-Type':'applicatioins/json'}

main(1)


