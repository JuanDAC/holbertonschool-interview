#!/usr/bin/node
const { get } = require('request');
const { argv } = require('process');

const number = argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${number}`;

const getCharacter = ([url, ...characters]) => {
  if (!url) {
    return;
  }

  get(url, (err, _, body) => {
    if (err) {
      console.log(err);
      return;
    }
    const { name } = JSON.parse(body);
    console.log(name);
    getCharacter(characters);
  });
};

get(url, (err, res, body) => {
  if (err) {
    console.log(err);
    return;
  }

  const { characters } = JSON.parse(body);

  getCharacter(characters);
});
