const fs = require('fs');

const filePath = 'input3.txt';
const content = fs.readFileSync(filePath, 'utf-8'); 
const regex = /(do\(\))|(don't\(\))|(mul\(\d*\,\d*\))/g;
const matches = content.match(regex);


var sum = 0;
var flag=1;

console.log(matches);
function mul(string)
{
    const regex2 = /\d+/g;
    const matches2 = string.match(regex2);
    return parseInt(matches2[0]) * parseInt(matches2[1]);
}
for (let i = 0; i < matches.length; i++) {
    if(matches[i]=="do()")
    {
        flag=1;
    }
    else if(matches[i]=="don't()")
    {
        flag=0;
    }
    else if(flag==1)
    {
        sum+=mul(matches[i]);
    }

}
console.log(sum);

// output : 95411583