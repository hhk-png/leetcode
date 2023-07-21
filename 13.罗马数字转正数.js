var romanToInt = function(s){
    var map = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };

    var re = map[s[0]];
    for(var i=1; i<s.length; i++){
        if(map[s[i-1]] >= map[s[i]]){
            re += map[s[i]];
        }else{
            re += map[s[i]] - 2*map[s[i-1]];
        }
    }

    return re;
};