var reverse = function (x) {
  // 1.
  // let fh = "";
  // if(x<0){
  //     fh = "-";
  //     x = 0-x;
  // }
  // // 通过将整数转换为字符串数组，然后调用reverse函数进行反转
  // re = (x+"").split("").reverse().join("");

  // if(re.length>10 || re.length === 10 && re > (x<0?"2147483648":"2147483647")){
  //     return 0;
  // }else{
  //     return fh+re;
  // }

  // 2.
  var re = 0;
  while (parseInt(x / 10)) {
    re = 10 * re + (x % 10);
    x = parseInt(x / 10);
  }

  if (re > 214748364 || re < -214748364) return 0;
  if ((re === 214748364 && x > 7) || (re === 214748364 && x < -8)) return 0;
  re = 10 * re + x;
  return re;
};
