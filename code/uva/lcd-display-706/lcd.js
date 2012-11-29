var digits={
  0: ['-', '|', '|', ' ', '|', '|', '-'],
  1: [' ', ' ', '|', ' ', ' ', '|', ' '],
  2: ['-', ' ', '|', '-', '|', ' ', '-'],
  3: ['-', ' ', '|', '-', ' ', '|', '-'],
  4: [' ', '|', '|', '-', ' ', '|', ' '],
  5: ['-', '|', ' ', '-', ' ', '|', '-'],
  6: ['-', '|', ' ', '-', '|', '|', '-'],
  7: ['-', ' ', '|', ' ', ' ', '|', ' '],
  8: ['-', '|', '|', '-', '|', '|', '-'],
  9: ['-', '|', '|', '-', ' ', '|', '-'],
  '-': [' ', ' ', ' ', '-', ' ', ' ', ' '],
};

function space(scale) {
  var s = '';
  scale = 1;
  for(var i=0; i < scale; i++) {
    s += ' ';
  }
  return s;
}

function r(rid, number, scale) {
  var s="";
  for(var ni=0; ni < number.length; ni++) {
    var digit = number[ni];

    s += ' ';
    for(var i=0; i < scale; i++) {
      s+=digits[digit][rid];			
    }
    s += ' ';

    s += space(scale);
  }
  s += '\n';

  return s;
}

function c(cid, number, scale) {
  var s="";
  for(var i=0; i < scale; i++) {
    for(var ni=0; ni < number.length; ni++) {
      var digit = number[ni];

      s+=digits[digit][cid];
      for(var j=0; j < scale; j++) {
        s+=' ';
      }
      s+=digits[digit][cid+1];

      s += space(scale);
    }
    s+='\n';
  }
  return s;
}

function lcd(number, scale) {
  return r(0, number, scale) +
    c(1, number, scale) +
    r(3, number, scale) +
    c(4, number, scale) +
    r(6, number, scale) ;
}

function refresh(event) {
  var pre = document.getElementById('lcd');
  var text = document.getElementById('txt').value;
  var scale = document.getElementById('scale').value;
  pre.textContent = lcd(text, scale);
  return false;
}

function refresh2(event) {
  refresh();
  return true;
}

onload = function() {
  document.getElementById('txt').focus();
  document.getElementById('txt').onchange = refresh;
  document.getElementById('txt').onkeyup = refresh2;
  document.getElementById('scale').onchange = refresh;
  refresh();
}
