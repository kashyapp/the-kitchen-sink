import csv

FAKE_PROD_ID = 'ZZZZZZZZZZZ'
old_rdr = csv.reader(open('old.csv'),delimiter=',')
new_rdr = csv.reader(open('new.csv'),delimiter=',')

old_row = old_rdr.next()
new_row = new_rdr.next()

while old_row or new_row:
  product_id_old = old_row[0] if old_row else FAKE_PROD_ID
  product_id_new = new_row[0] if new_row else FAKE_PROD_ID

  currprod = min(product_id_old, product_id_new)
  sum_old = 0
  sum_new = 0

  while product_id_old == currprod:
    sum_old += int(old_row[2])
    try:
      old_row = old_rdr.next()
      product_id_old = old_row[0]
    except Exception as err:
      old_row = None
      product_id_old = FAKE_PROD_ID

  while product_id_new == currprod:
    sum_new += int(new_row[2])
    try:
      new_row = new_rdr.next()
      product_id_new = new_row[0]
    except Exception as err:
      new_row = None
      product_id_new = FAKE_PROD_ID

  if sum_old != sum_new:
    print currprod,sum_new
