## Background ##
Hebrew morphology is complicated, and does not lend itself to simple **prefix/suffix stemming**, as done in most search engines (e.g. **Lucene**, **Xapian**) via e.g. the **Snowball** algorithm collection.

**libhspell** is a free (GPL) library providing lexicon-based morphologically-correct Hebrew stemming.  It supports the ISO-8859-8 encoding only, and the official Hebrew undiacriticized (niqqud-less) spelling of Hebrew words.
## The Project ##
The **hebstem** project aims to create the **glue** necessary to use libhspell's morphological stemming in the Lucene and Xapian search engines (and others, possibly).  To do that, it does the following:
  * implement a Hebrew stemmer class for each search engine, calling libhspell
  * transcode strings from UTF-8 to ISO-8859-8, possibly after some pre-processing
  * integrate libhspell to extension/plug-in systems of Lucene and Xapian

## License ##
hebstem is available under the GNU General Public License v2.