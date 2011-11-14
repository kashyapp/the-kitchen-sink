#!/usr/bin/env python
import urllib2
import csv

rdr = csv.reader(urllib2.urlopen('https://docs.google.com/spreadsheet/pub?hl=en_US&hl=en_US&key=0Av8PXzmx5bycdGkxcnFGOFlkRFV4RUNjMzVlU3hLVEE&single=true&gid=0&output=csv'))
mapping = {}
for row in rdr:
    if row and len(row) >= 2:
        mapping[row[0].strip()] = row[1].strip()

print mapping
