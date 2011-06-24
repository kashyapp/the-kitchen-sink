import csv

FAKE_PROD_ID = 'ZZZZZZZZZZZ'
old_rdr = csv.reader(open('old.csv'),delimiter=',')
new_rdr = csv.reader(open('new.csv'),delimiter=',')

f1 = old_rdr.next()
f2 = new_rdr.next()

while f1 or f2:
  prod1 = f1[0] if f1 else FAKE_PROD_ID
  prod2 = f2[0] if f2 else FAKE_PROD_ID

  currprod = min(prod1, prod2)
  sum1 = 0
  sum2 = 0

  while prod1 == currprod:
    sum1 += int(f1[2])
    try:
      f1 = old_rdr.next()
      prod1 = f1[0]
    except Exception as err:
      f1 = None
      prod1 = FAKE_PROD_ID

  while prod2 == currprod:
    sum2 += int(f2[2])
    try:
      f2 = new_rdr.next()
      prod2 = f2[0]
    except Exception as err:
      f2 = None
      prod2 = FAKE_PROD_ID

  if sum1 != sum2:
    print currprod,sum2
