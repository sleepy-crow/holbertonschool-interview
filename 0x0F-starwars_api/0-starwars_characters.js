#!/usr/bin/node
const request = require('request');
const movieID = parseInt(process.argv[2]);
const movieOfSaga = 'https://swapi-api.hbtn.io/api/films/' + movieID;

request(movieOfSaga, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const Body = JSON.parse(body);
    for (const chara of Body.characters) {
      request(chara, function (err, resp, bod) {
        if (err) {
          console.log('code:', response.statusCode);
        } else {
          console.log(JSON.parse(bod).name);
        }
      });
    }
  }
});
