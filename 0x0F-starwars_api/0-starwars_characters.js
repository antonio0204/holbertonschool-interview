#!/usr/bin/node

/*
Get characters from Star Wars Movie
*/

const URL = 'https://swapi-api.hbtn.io/api/';
const request = require('request');
const idMovie = process.argv[2];

async function getRequest (url) {
  return new Promise(function (resolve, reject) {
    request.get(url, function (err, resp, body) {
      if (err) {
        reject(err);
      } else {
        resolve(JSON.parse(body));
      }
    });
  });
}

(async () => {
  return getRequest(URL + 'films/' + idMovie);
})().then(async (movie) => {
  if (movie.detail !== 'Not found') {
    for (const ch of movie.characters) {
      const character = await getRequest(ch);
      if (character.detail === undefined) {
        console.log(character.name);
      }
    }
  }
});
