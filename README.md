# NoteIn

A simple note-taking management application that allows you to use your file
system as a workspace for your notes.

## Generating a Compilation Database

If you want to have your Visual Studio Code fully setup to work with this
project it's highly recommended that you setup a compilation database to work
with [SonarLint](https://www.sonarsource.com/products/sonarlint/) and other
tools. In order to automate things a bit you'll be required to have
[Bear](https://github.com/rizsotto/Bear) installed in your system. After that,
all that you need to do is run:

```bash
make compiledb
```

## Testing

In order for you to ensure tha the library is working correctly and also to have
an example file to test/play around with, after cloning this repository simply
run:

```bash
make run
```

## License

This project is licensed under the [MIT License](/LICENSE).
