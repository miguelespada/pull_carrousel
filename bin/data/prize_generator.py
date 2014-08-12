import random
import time
import json

from operator import itemgetter, attrgetter

dateFormat =  '%d/%m/%Y %H:%M:%S'

startTime = time.strptime("14/08/2014 10:05:00", dateFormat)
endTime = time.strptime("14/08/2014 21:50:00", dateFormat)

def generateDate(start, end, prop):
    stime = time.mktime(start)
    etime = time.mktime(end)
    ptime = stime + prop * (etime - stime)
    return time.localtime(ptime)

def formatDate(date):
  return time.strftime('%H:%M:%S', date)

def printPremios(premios):
  toJson = []
  for premio in premios:
    toJson.append({"date" : formatDate(premio[0]), "prize" : premio[1], "enabled" : 1})
  print json.dumps(toJson, indent=4, separators=(',', ': '), sort_keys=True)

def distribute(objects):
  slices = len(objects)
  dist = []
  for i in range(slices):
    initSlice = generateDate(startTime, endTime, i / float(slices))
    endSlice = generateDate(startTime, endTime, (i + 1) / float(slices))
    date = generateDate(initSlice, endSlice, random.random())
    dist.append((date, objects[i]))
  return dist

premios = []
premios += distribute(["gafas"] * 50)
premios += distribute(["auriculares"] * 50)
premios += distribute(["descuento"] * 25)
extra = ["ipad", "impresora", "gopro", "bicicleta"]
extra += (["skate"] * 5)
random.shuffle(extra)
premios += distribute(extra)

premios = sorted(premios, key=itemgetter(0))
printPremios(premios)