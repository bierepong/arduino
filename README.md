# Arduino driver for BeerPong

## Data exchange

Data are sent on USB (speed: 115200) every seconds

```
sensor(0,0,0,0,0,0);
```

Regexp to catch data: `^sensor\((\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\);`
