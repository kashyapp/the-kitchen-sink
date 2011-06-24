import csv

class Reader:
  handle = None
  curr = None

  def setcurr(self, row):
    self.curr = row
    self.curr[2] = int(self.curr[2])

  def __init__(self, filename):
    self.handle = csv.reader(open(filename), delimiter=',')
    self.setcurr(self.handle.next())

  def next(self):
    try:
      temp = self.handle.next()
      while (temp[0] == self.curr[0]):
        self.curr[2] += int(temp[2])
        temp = self.handle.next()
      else:
        row = self.curr
        self.setcurr(temp)
        return row
    except StopIteration:
      return self.curr

old_r = Reader('old.csv')
new_r = Reader('new.csv')


