//26% speed

/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    if (x == 0 || x > 2**31-1 || x < 0-2**31) return 0;

    var neg = false;
    if (x < 0) {
        neg=true;
        x*=-1;
    }
    var ans = rev(x);
    if (ans == 0 || ans > 2**31-1 || ans < 0-2**31) return 0;
    if (neg) {
        return ans*-1;
    }
    return ans;
};

var rev = function(x) {
  var length = Math.floor(Math.log10(x)) +1;
    var i, result=0;
    for (i=length-1; i >= 0; i--) {
       // console.log(10**i);
       // console.log(Math.floor(x/10**i));
        var digit = Math.floor(x/10**i);
        x= x%10**i;
        result+=digit* 10**(length-i-1);
    }
    return result;
};
