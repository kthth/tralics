Documentation of Tralics
========================

Content: A first [example](#ex1), a second [example](#ex2),
interpretation of the [transcript file](#trans) and
[parameterisation](#parm).

Introduction
------------

This web page is assumed to explain how to read the *Tralics*
documentation, and gives some examples. In general, LaTeX input is
written `\like{this}` and the XML output `<like>that</like>`. You run
*Tralics* on a file myfile.tex via the command tralics myfile. You can
provide some options, before or after the file name. This may produce
*errors* or other *messages*.

Standard example
----------------

Let\'s consider a TeX file, named hello1.tex that consists of the
following lines.

::: {.container .ltx-source}
    \documentclass{article}
    \begin{document}
    Hello, world!
    \end{document}
:::

You compile this file by saying tralics hello1.tex; the extension may be
omitted. If you think that the output is too verbose, you can use the
silent option: say tralics hello1 -silent. Then you will see the
following 8 lines on the terminal

::: {.container .tty_out}
    This is tralics 2.15.4, a LaTeX to XML translator, running on maclaurin
    Copyright INRIA/MIAOU/APICS/MARELLE 2002-2015, Jos\'e Grimm
    Licensed under the CeCILL Free Software Licensing Agreement
    Starting translation of file hello1.tex.
    Document class: article 2011/05/09 v1.2 Article document class for Tralics
    Output written on hello1.xml (176 bytes).
    No error found.
    (For more information, see transcript file hello1.log)
:::

The fifth line might be *Dummy default configuration file used*; this
indicates that *Tralics* is unable to find the configuration. The fifth
line may be missing; this means that the article.clt file was not found.
Note that *Tralics* never reads the file article.cls, and does not
complain if class files or packages are missing. You can use the option
-confdir=bar to indicates that the configuration file or class file is
located in the bar directory; this option can be given more than once,
in order to specify more than one location.

In some cases, when *Tralics* thinks you are compiling the Raweb, a
fatal error may be signaled before the transcript file is opened. In all
other cases, it writes some information on the transcript file (in the
example above, the file hello1.log has 186 lines; in verbose mode, this
could be 1071). In particular all errors appear in this file. In some
cases, a file foo.img is created: it holds some information about
graphic files when `\includegraphics` is used. Generally, an XML file is
produced, it looks like the following

::: {.container .xml_out}
    <?xml version='1.0' encoding='UTF-8'?>
    <!DOCTYPE std SYSTEM 'classes.dtd'>
    <!-- Translated from latex by tralics 2.15.4, date: 2015/08/20-->
    <std>
    <p>Hello, world!
    </p>
    </std>
:::

Small example
-------------

Assume that your document source contains the lines that follow.

::: {.container .ltx-source}
    % Example file tralics-ex1.tex $Revision: 1.1 $
    \begin{xmlelement}{preview}
    This is a test. An \unknown command. A math formula $a^$.
    \def\test#1#2?{#1,#2.}\test ok?\typeout{A message}
    \end{xmlelement}
    % EOF
:::

If you run *Tralics* on the document, you will see the following on the
terminal:

::: {.container .tty_out}
    This is tralics 2.2 (pl2), a LaTeX to XML translator
    % (some lines omitted here) 
    Error signaled at line 3 of file tralics-ex1.tex:
    Undefined command \unknown.
    Error signaled at line 3 of file tralics-ex1.tex:
    Math formula should not finish with ^.
    A message
    % (lines omitted here) 
    (For more information, see transcript file tralics-ex1.log)
:::

We indicated with colors some omissions. We left the identification line
(this is a very old version), the error messages, the result of
`\typeout`, and the last line. Note that everything that is printed on
the screen is also printed in the transcript file.

Four lines are printed because *Tralics* noticed two errors on the third
line. The fourth line is OK, but the `\test` macro has a weird syntax.
There is no `\documentclass`, no `\begin{document}` and no
`\end{document}`: these commands are useful, but there absence is not an
error. The `xmlelement` environment allows you to put XML elements of
any name in the result file.

The XML code generated by *Tralics* is the following:

::: {.container .xml_out}
    <?xml version='1.0' encoding='iso-8859-1'?>
    <!DOCTYPE unknown SYSTEM 'unknown.dtd'>
    <!-- translated from latex by tralics 2.2 (pl2)-->
    <unknown>
    <p><preview>This is a test. An <error l='3' c='Undefined command '/>command. % CR added
    A math formula <formula type='inline'><math xmlns='http://www.w3.org/1998/Math/MathML'>% CR added
    <mi>a</mi></math></formula>.
    o,k.
    </preview>
    </p></unknown>
:::

Some comments: in TeX, a newline character is equivalent to a space
(unless followed by another newline character, the result being `\par`).
In some cases, spaces disappear (in particular after a space); if a line
is terminated by a space and a new line, and the next line starts with a
space, the translator sees only one space, the newline character; its
translation is a newline character. As a result most line breaks are the
same in the input file and in the resulting XML document. On the other
hand, spaces are ignored in math mode, and all math formulas produce
long lines. In our examples, we have edited all these formulas, but for
the example above, we have indicated (via blue comments) the places
where new line characters have been added.

By default, every error produces an error element in the XML file; for
the current version of *Tralics*, the first element is
`<error n='\unknown' l='3' c='Undefined command'/>` and the second is
`<error n='$' l='3' c='Math formula should not     finish with ^'/>`.
You can invoke *Tralics* with the -noxmlerror flag, case where no such
elements are generated. You can invoke *Tralics* with the -noundefmac
flag, in the case, the XML file will contain `\unknown` instead of the
`<error>` element. You can invoke *Tralics* with the -nomathml flag, in
the case, the XML file will not contain MathML elements. Using -nomathml
-noxmlerror yields the following file (as the math expression is not
fully converted, there is one less error).

::: {.container .xml_out}
    <?xml version='1.0' encoding='iso-8859-1'?>
    <!DOCTYPE unknown SYSTEM 'unknown.dtd'>
    <!-- translated from latex by tralics 2.7 (pl5)-->
    <unknown>
    <p><preview>This is a test. An command. A math formula 
    <texmath type='inline'>a^</texmath>.
    o,k.
    </preview>
    </p></unknown>
:::

We have designed an XSLT style sheet (named preview.xsl) whose purpose
is to remove from the XML output everything but the `<preview>`
elements. It is possible to process the resulting document like any
other XML document, in this case, we convert it to XSL-fo, via the
simplefo.xsl style sheet then to dvi and PostScript. We hacked the
fotex.sty file, so that the following command
`\RequirePackage[active]{preview}` (preview package by David Kastrup) is
activated. As a result, lots of code inserted by the simplefo.xsl style
sheet becomes useless, and only `<preview>` elements are used. As a
consequence, the PostScript contains only the translation of the two
lines of code. Converting to an image, it is ![preview
example](/img/img_5.png) In the documentation, all images are obtained
in this fashion.

The transcript file {#trans}
-------------------

The transcript file contains more or less lines, depending on whether
`\tracingall` and friends are used. You can also use the option
-verbose, this will trace everything, including the bootstrap phase.

The format of the file is like that of TeX. A line of the form
*{catcode}* says that the `\catcode` command has been seen; the line
*+scanint for \\catcode-\>38* says that `\catcode` has fetched the
integer 38 (such information is missing in the TeX transcript); a line
of the form *{begin-group character}* or *{math shift character}* says
that a character was interpreted as a command (TeX indicates which one,
open brace or dollar, but this information is less useful), a line of
the form *\\foo \#1\#2\#3-\>\#2* explains that a macro is about to be
expanded, it is followed by the values of the arguments.

When TeX sees a character, for instance when handling `Hello, world!`,
it traces it as *{the letter H}*; in order to reduce the size of the
transcript, only the first letter of a group is printed, so you will see
*{horizontal mode: the letter H}*, then *{blank space }*, and *{the
letter w}* and finally *{blank space }*. On the other hand, *Tralics*
shows all characters, in the form *Character sequence: Hello, world! .*
The period here is not part of the sequence, it makes the space that
precedes visible (this space is the end-of-line character). These
characters are kept in a buffer, and later on transferred to the current
XML element, you will see *{Text:Hello, word!\^\^J}*. Note that \^\^J
stands for a newline character (generally, a line break in the source
gives a line break in the XML file). If a letter, like H, is seen in
vertical mode, then TeX starts a new paragraph and switches to
horizontal mode; this is indicated in some cryptic manner. On the other
hand, when *Tralics* creates a new paragraph it says so via: *{Push p
1}* (the number says how many elements are on the XML stack). At the end
of the paragraph you will see *{Pop 1: document_v p_v}*; after popping,
the stack holds only the document element; you can see that both
elements were entered in vertical mode (*Tralics* does indicate the
switch to horizontal mode).

The trace holds also lines of the form *++ Input stack empty at end of
file* that explain interaction with the file system, lines of the form
*+stack: level + 2 for brace entered on line 13* whenever a new slot in
the save stack is allocated, and *+stack: level - 2 for brace from line
13* when the slot is deallocated; you may also see *+stack: restoring
integer value 4 for \\catcode38* before deallocation.

We shall comment now (a part of) the full trace of the previous example.

::: {.container .log_out}
    Transcript file of tralics 2.15.4 for file tralics-ex1.tex 
    Copyright INRIA/MIAOU/APICS/MARELLE 2002-2015, Jos\'e Grimm
    Tralics is licensed under the CeCILL Free Software Licensing Agreement
    Start compilation: 2015/08/20 13:25:44 
    OS: Apple, machine maclaurin
:::

The first line indicates the *Tralics* version and the name of the file
to be compiled; this is followed by the Copyright notice. Then comes the
compilation date and time, followed by the operating system and the name
of the computer.

::: {.container .log_out}
    Starting translation of file tralics-ex1.tex. 
    Output encoding: UTF8  (idem transcript).
    Left quote is ` right quote is '
    ++ Input encoding is 1 (iso-8859-1) for the main file
:::

You can see that that the XML file, as well as the transcript file will
be encoded in UTF-8, while the input file is, by default, assumed to be
latin1 (the file can say how it is encoded, but the file is not yet
interpreted). The example is all ASCII, so this is irrelevant here.
Moreover, left and right code have there default value.

::: {.container .log_out}
    ++ file .tralics_rc does not exist.
    ++ file ../confdir/.tralics_rc exists.
    Configuration file identification: standard $ Revision: 2.24 $
    Read configuration file ../confdir/.tralics_rc.
    Configuration file has type \documentclass
    No \documentclass in source file
    Using some default type
    dtd is unknown from unknown.dtd (standard mode) 
    OK with the configuration file, dealing with the TeX file... 
    There are 6 lines 
    Starting translation
:::

You see where *Tralics* searches for its configuration file, .tralics_rc
and where it is found. This configuration file says that the document
type to use comes from the `\documentclass` command of the main file;
however there is no `\documentclass` command in this file, so a default
DTD will be used. For explanations see
[here](titlepage.html#explanations). After that, *Tralics* is ready to
translate the six lines of the file. But, before this, there is a
bootstrap phase.

::: {.container .log_out}
    {\countdef \count@=\count255}
:::

The transcript file contains many line of this form; this one says that
`\count@` is the counter 255. (note: this is the largest counter in
plain TeX; however `\newcounter` never allocates this one).

::: {.container .log_out}
    {\countdef \c@enumi=\count22}
    {globally changing \theenumi=undefined}
    {into \theenumi=macro:->\number \c@enumi }
:::

Whenever a counter is created, here `enumi`, a command is defined; you
can see here that this globally changes an undefined command into a
macro.

::: {.container .log_out}
    {\countdef \c@section=\count46}
    {globally changing \thesection=undefined}
    {into \thesection=macro:->\number \c@section }
    {newcounter->\cl@chapter}
    +stack: level + 2 for brace entered on line 0
    {\let \@elt \relax}
    {changing \@elt=undefined}
    {into \@elt=\relax}
    \cl@chapter ->
    +stack: killing \@elt
    +stack: level - 2 for brace from line 0
    {globally changing \cl@chapter=macro:->}
    {into \cl@chapter=macro:->\@elt {section}}
:::

Here we define a counter that depends on another counter. This results
into redefining `\cl@chapter`. Inside a group, `\@elt` is redefined by
be `\relax`. Whenever a group is opened or closed, *Tralics* indicates
the line number; here this is still zero. We shall omit most of the
bootstrap phase, and focus on a single line.

::: {.container .log_out}
    [13] {\catcode`\&=13\global\def&{\char38 }}%
    {begin-group character}
    +stack: level + 2 for brace entered on line 13
    {\catcode}
    +scanint for \catcode->38
    +scanint for \catcode->13
    {changing \catcode38=4 into \catcode38=13}
    {\global}
    {\global\def}
    {globally changing &=undefined}
    {into &=macro:->\char 38 }
    {end-group character}
    +stack: restoring integer value 4 for \catcode38
    +stack: level - 2 for brace from line 13
:::

Whenever a line is read, it is printed in the transcript file, preceded
by the line number in square brackets. Here we define the value of the
ampersand character as an active character. For this, we start changing
its category code in a group; when the closing brace is seen, the old
value is restored. Since the ampersand is globally defined, it will not
be restored. Note that `\char38` could have been replaced by
`\\char`&\`.

::: {.container .log_out}
    [73] %% End bootstrap commands for latex
    ++ Input stack empty at end of file
:::

All the bootstrap commands were in a virtual file; *Tralics* says here
that the input stack is empty. This means the real start of the
translation.

::: {.container .log_out}
    [1] % Example file tralics-ex1.tex $Revision: 1.16 $
    [2] \begin{xmlelement}{preview}
    {\begin}
    {\begin xmlelement}
    +stack: level + 2 for environment entered on line 2
    {\xmlelement}
    {Push argument 1}
    Character sequence: preview.
    {Text:preview}
    {Pop 1: document_v argument_v}
    {Push p 1}
    {Push ELT 2}
:::

The first token in the file is the `\begin` command. This command reads
an environment name, which is indicated on the next line. A new level of
grouping is entered and an item is pushed on the save stack (this holds
the name of the environment). Then `\xmlelement` is executed, thus
logged. This command reads a name, but using a different algorithm than
`\begin`. The idea is to translate the next argument into a temporary
element, and convert it into a string; the line *{Text:preview}* shows
what is put in the temporary, this will be the name of the box. The XML
stack is used for this purpose, the temporary is named "argument" in
this context.

Once `\xmlelement` has found the name of the box to create, it leaves
vertical mode (i.e., starts a new paragraph), then starts a new XML
element with the given name. So two objects are push on the XML stack.

::: {.container .log_out}
    [3] This is a test. An \unknown command. A math formula $a^$.
    Character sequence: This is a test. An .
    {Text:This is a test. An }
    Error signaled at line 3 of file tralics-ex1.tex:
    Undefined command \unknown.
    Character sequence: command. A math formula .
    {math shift character}
    {Text:command. A math formula }
    {reassigning \@curmathfont=0}
    +stack: level + 3 for math entered on line 3
    +stack: level - 3 for math from line 3
    Math: $a^$
    {Inline formula
    1 ME 11 - char a - 0
    2 ME 7 - char ^ - 0
    }
    Error signaled at line 3 of file tralics-ex1.tex:
    Math formula should not finish with ^.
    Character sequence: . .
:::

The third line holds some letters, a command, some letters, a formula
and more letters. Since the command is undefined, no line is added to
the transcript (except the two error lines). Now comes the math formula.
There are two passes; for the first pass, you can see that everything
happens in a group, and that the current math font is set to zero; after
that comes a cryptic description of the formula; the second pass signals
an error.

::: {.container .log_out}
    [4] \def\test#1#2?{#1,#2.}\test ok?\typeout{A message}
    {\def}
    {changing \test=undefined}
    {into \test=macro:#1#2?->#1,#2.}
    \test #1#2?->#1,#2.
    #1<-o
    #2<-k
    Character sequence: o,k..
    {\typeout}
    A message
    Character sequence:  .
:::

Here is a macro definition, followed by by a macro expansion. There are
two character sequences: one comes from the body of the macro, and one
from the end-of-line character.

::: {.container .log_out}
    [5] \end{xmlelement}
    {\end}
    {Text:.
    o,k.
    }
:::

When the `\end` command is seen, all characters gathered so far are put
into the current XML element; there is a dot from line 3, four
characters from line 4, and two newline characters.

::: {.container .log_out}
    {\end xmlelement}
    {\endxmlelement}
    {Pop 2: document_v p_v ELT_h}
    {\endgroup (for env)}
    +stack: killing \test
    +stack: ending environment xmlelement; resuming document.
    +stack: level - 2 for environment from line 2
    Character sequence:  .
:::

The `\end` command grabs its argument, then executes `\endxmlelement`.
This command closes the current paragraph (assuming one has been opened,
which is not the case here) then closes the current element, and pops
the XML stack. After that the `\end` command pops the save stack; the
`\test` command is restored to its previous value (undefined) and the
current environment is shown.

::: {.container .log_out}
    [6] % EOF
    ++ Input stack empty at end of file
    {Text:
    }
:::

Line 6 is ignored, as it is commented out. Since this is the last line
of the file, *Tralics* checks if there is another file on its stack;
since the stack is empty, this is the end of the job. The characters
gathered so far (the newline corresponding to the end of line 5) are
inserted in the current XML element.

::: {.container .log_out}
    Bib stats: seen 0 entries.
    Math stats: formulas 1, kernels 0, trivial 0, \mbox 0, large 0, small 0.
    Buffer realloc 1, string 1353, size 12379, merge 0
    Macros created 178, deleted 8; hash size 2400; foonotes 0.
    Save stack +18 -18.
    Attribute list search 1528(1509) found 1083 in 1129 elements (1120 at boot).
    Number of ref 0, of used labels 0, of defined labels 0, of ext. ref. 0.
    Output written on tralics-ex1.xml (453 bytes).
    There were 2 errors.
    (For more information, see transcript file tralics-ex1.log)
:::

Finally *Tralics* shows some statistics, they are explained
[here](doc-step.html#stats).

Parameterisation {#parm}
----------------

You can change the name of some elements. For instance, consider the
following input.

::: {.container .ltx-source}
    \documentclass{article}
    % Example file tralics-ex2.tex $Revision: 1.1 $
    \begin{document}
    \begin{itemize} \item [A] B \end{itemize}
    \begin{glossaire} \glo{x}{y}\end{glossaire}
    \part{A}\chapter{B}\section{C} \subsection{D}
    \subsubsection{E}\paragraph{F} \subparagraph{G}
    \begin{motscle}first,second \end{motscle}
    \mbox{$a$}
    \declaretopic{10}{foo}\caption[opt]{ok}
    \footnote{anote} \includegraphics{x.ps}
    \begin{figure}\includegraphics{y.ps}\end{figure}
    \end{document}
:::

It will be translated into

::: {.container .xml_out}
    <list type='simple'><label>A</label>
    <item id='uid25'><p>B </p>
    </item></list>
    <list type='gloss'><head>Glossary</head><label>x</label><item><p>y</p>
    </item></list></div3></div2></div1></div0>
    <div0 id='uid26'><head>A</head>
    </div0>
    <div0 id='uid27'><head>B</head>
    </div0>
    <div0 id='uid28'><head>C</head>
    <div1 id='uid29'><head>D</head>
    <div2 id='uid30'><head>E</head>
    <div3 id='uid31'><head>F</head>
    <div4 id='uid32'><head>G</head>
    <keywords><term>first</term>
    <term>second</term>
    </keywords><p><mbox><formula type='inline'><simplemath>a</simplemath></formula></mbox>
    <topic num='10'><t_titre>foo</t_titre></topic>
    <caption>ok</caption>
    <note id='uid33' place='foot'>anote</note> <figure file='x'/>
    </p>
    <figure file='y' id='uid34'></figure>
    </div4></div3></div2></div1></div0>
:::

The commands in blue are specific to the raweb; they are no longer
defined. Without them, the current translation is the following. Note
that `\part`, `\chapter` and `\section` are considered equivalent by the
article class: they generate a `div0` element, and are no nested.
However the `id-text` attributes are different (translation of
`\thepart`, `\thechapter`, etc).

::: {.container .xml_out}
    <list type='simple'>
      <label>A</label>
      <item id-text='1' id='uid1'><p noindent='true'>B</p></item>
    </list>
    <div0 id-text='I' id='cid1'><head>A</head></div0>
    <div0 id-text='1' id='cid2'><head>B</head></div0>
    <div0 id-text='1' id='cid3'><head>C</head>
      <div1 id-text='1.1' id='uid2'><head>D</head>
        <div2 id-text='1.1.1' id='uid3'><head>E</head>
          <div3 id-text='1.1.1.1' id='uid4'><head>F</head>
            <div4 id-text='1.1.1.1.1' id='uid5'><head>G</head>
              <keywords>
                <term>first</term>
                <term>second</term>
              </keywords>
              <p>
                <mbox><formula type='inline'><simplemath>a</simplemath></formula></mbox>
                <caption>ok</caption>
                <alt_head>opt</alt_head>
                <note id-text='1' id='uid6' place='foot'>anote</note> 
                <figure rend='inline' file='x' extension='ps'/>
              </p>
              <figure file='y' extension='ps' id-text='1' id='uid7' rend='figure'/>
            </div4>
          </div3>
        </div2>
      </div1>
    </div0>
:::

Consider the following file (it is called unused.tcf).

::: {.container .ltx-source}
    ## This is an example of a configuration file for tralics
    ## Copyright 2006 Inria/apics, Jose' Grimm
    ##  $Id: unused.tcf,v 1.1 2006/07/17 09:09:06 grimm Exp  $
    ## tralics ident rc=unused.tcf  $Revision: 1.1  $

      xml_labelitem_name = "Xlabel"
      xml_gloitem_name = "Xglolabel"
      xml_item_name = "Xitem"
      xml_div0_name = "Xdiv0"
      xml_div1_name = "Xdiv1"
      xml_div2_name = "Xdiv2"
      xml_div3_name = "Xdiv3"
      xml_div4_name = "Xdiv4"
      xml_div5_name = "Xdiv5"
      xml_div6_name = "Xdiv6"
      xml_subfigure_name = "Xsubfigure"
      xml_row_name = "Xrow"
      xml_cell_name = "Xcell"
      xml_keywords_name = "Xkeywords"
      xml_term_name = "Xterm"
      xml_mbox_name = "Xmbox"
      xml_topic_name = "Xtopic"
      xml_caption_name = "Xcaption"
      xml_footnote_name = "Xnote"
      xml_fbox_name = "Xfbox"
      xml_box_name = "Xbox"
      xml_picture_name = "Xpicture"
      xml_graphics_name = "Xgraphics"
      xml_figure_name = "Xfigure"
      xml_table_name = "Xtable"
      xml_Table_name = "XTable"
      xml_bezier_name = "Xbezier"
      xml_put_name = "Xput"
      xml_line_name = "Xline"
      xml_vector_name = "Xvector"
      xml_oval_name = "Xoval"
      xml_dashline_name = "Xdashline"
      xml_drawline_name = "Xdrawline"
      xml_dottedline_name = "Xdottedline"
      xml_circle_name = "Xcircle"
:::

Compile with tralics tralics-ex2 -type unused -trivialmath=2, you get

::: {.container .xml_out}
    <unknown>
    <list type='simple'><Xlabel>A</Xlabel>
    <Xitem id-text='1' id='uid1'><p noindent='true'>B</p>
    </Xitem></list>
    <Xdiv0 id-text='I' id='cid1'><head>A</head>
    </Xdiv0>
    <Xdiv0 id-text='1' id='cid2'><head>B</head>
    </Xdiv0>
    <Xdiv0 id-text='1' id='cid3'><head>C</head>
    <Xdiv1 id-text='1.1' id='uid2'><head>D</head>
    <Xdiv2 id-text='1.1.1' id='uid3'><head>E</head>
    <Xdiv3 id-text='1.1.1.1' id='uid4'><head>F</head>
    <Xdiv4 id-text='1.1.1.1.1' id='uid5'><head>G</head>
    <Xkeywords>
    <Xterm>first</Xterm>
    <Xterm>second</Xterm>
    </Xkeywords><p><Xmbox><formula type='inline'><simplemath>a</simplemath></formula></Xmbox>
    <caption>ok</caption><alt_head>opt</alt_head>
    <Xnote id-text='1' id='uid6' place='foot'>anote</Xnote> 
    <Xfigure rend='inline' file='x' extension='ps'/></p>
    <figure file='y' extension='ps' id-text='1' id='uid7' rend='Xfigure'/>
    </Xdiv4></Xdiv3></Xdiv2></Xdiv1></Xdiv0></unknown>
:::