# Golden Section Search

Very basic algorithm. We have an [unimodal function](https://en.wikipedia.org/wiki/Unimodality), and we want to find it's minimum (by definition of unimodality it will be the only local minimum).

In my code example the algorithm finds minimum of `sin(x) - 10 / x`, on segment `[8, 12]` which will print:

```
Point of minimum: 10.9115
Value at minimum: -1.91293
```

![Function graphic build with Desmos](https://github.com/dmitrii-artuhov/optimization-algorithms/blob/master/2-golden-section-search/assets/golden-section-search-1.jpg)

More info here (rus): [click](http://www.machinelearning.ru/wiki/index.php?title=%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%B7%D0%BE%D0%BB%D0%BE%D1%82%D0%BE%D0%B3%D0%BE_%D1%81%D0%B5%D1%87%D0%B5%D0%BD%D0%B8%D1%8F._%D0%A1%D0%B8%D0%BC%D0%BC%D0%B5%D1%82%D1%80%D0%B8%D1%87%D0%BD%D1%8B%D0%B5_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4%D1%8B).