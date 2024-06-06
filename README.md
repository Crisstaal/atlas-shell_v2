<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <h1>Custom Shell Project</h1>
    <p>This simple UNIX command line interpreter provides a basic shell environment.</p>

<h2>Features</h2>
    <ul>
        <li>Execution of commands with arguments</li>
        <li>Handling of environment variables</li>
        <li>Built-in commands</li>
        <ul>
            <li><strong>cd [path]</strong>: Changes the current directory to the specified path. If no argument is provided, it changes to the home directory.</li>
            <li><strong>exit [status]</strong>: Exits the shell with the specified status. If no status is provided, it exits with the status of the last executed command.</li>
            <li><strong>env</strong>: Prints the current environment variables.</li>
        </ul>
    </ul>

<h2>Compilation</h2>
    <p>To compile the project, use the following command:</p>
    <pre><code>gcc -Wall -Werror -Wextra -pedantic *.c -o hsh</code></pre>

<h2>Running the Shell</h2>
    <p>After compilation, you can run the shell with:</p>
    <pre><code>./hsh</code></pre>

<h2>Manual Page</h2>
    <p>To read the manual page, use:</p>
    <pre><code>man ./man_1_hsh.1</code></pre>

<h2>Usage Examples</h2>
    <h3>Running a command:</h3>
    <pre><code>$ ./hsh
($) /bin/ls
hsh exit.c ashv2.c etc.c
($) exit
$</code></pre>

<h3>Changing directory:</h3>
    <pre><code>$ ./hsh
($) cd /usr
($) pwd
/usr
($) exit
$</code></pre>

</body>
</html>
