// speed 15%, memory %18
// hmm so bad...
/**
 * @param {string[]} votes
 * @return {string}
 */
var rankTeams = function(votes) {
  let charMap = new Map()
  let voteArr = [];
  var addvote = function(char, vote) {
    if (charMap.has(char)) {
      charMap.set(char, charMap.get(char) + vote)
    } else {
      charMap.set(char, vote)
    }
  };
  var strpowpos = function(index, string) {
    //   console.log('reverse index', string.length - index - 1)
    return string.length - index - 1
  };
  for (voteIndex = 0; voteIndex < votes.length; voteIndex++) {
    for (charIndex = 0; charIndex < votes[voteIndex].length; charIndex++) {
      addvote(
          votes[voteIndex][charIndex],
          Math.pow(votes.length + 1, strpowpos(charIndex, votes[voteIndex])))
    }
  }
  charMap.forEach((value, char) => {voteArr.push({value: value, char: char})})
  voteArr.sort((elem1, elem2) => {
    if (elem2.value == elem1.value) {
      if (elem2.char < elem1.char)
        return 1;
      else
        return -1
    }
    return elem2.value - elem1.value
  })
  return voteArr.map(obj => obj.char).join('');
};

// break the location of the character in the string into
// decimal number
console.log('rank teams function')
if (rankTeams(['ABC', 'ACB', 'ABC', 'ACB', 'ACB']) == 'ACB') {
  console.log('success')
}
else {
  console.log('fail')
}
if (rankTeams(['BCA', 'CAB', 'CBA', 'ABC', 'ACB', 'BAC']) == 'ABC') {
  console.log('success')
} else {
  console.log('fail')
}
console.log('M M M M M M')
console.log(rankTeams(['M', 'M', 'M', 'M', 'M', 'M']))