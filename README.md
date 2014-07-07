count emotional words with CVS (simple not-expression)

```sh
$ ./cask < input
suk ika kow yas iya awa tak odo haj yor
1 0 0 1 0 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
```

The first line is the set of labels.
That disappears with `-s`.

```sh
$ ./cask -s < ./input
1 0 0 1 0 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0
```
