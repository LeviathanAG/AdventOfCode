const fs = require('fs');

const filePath = 'input3.txt';
const content = fs.readFileSync(filePath, 'utf-8'); 
const regex = /mul\(\d*\,\d*\)/g;
const matches = content.match(regex);
const regex2 = /\d+/g;

var sum = 0;

for (let i = 0; i < matches.length; i++) {
    const matches2 = matches[i].match(regex2);
    sum += parseInt(matches2[0]) * parseInt(matches2[1]);
}

console.log(sum);