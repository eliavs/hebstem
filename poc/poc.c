// poc.c -- proof of concept of stemming Hebrew through libhspell
//
// by Asaf Bartov <asaf.bartov@gmail.com>

// It is assumed that hspell was installed, i.e. that the dictionary is available at /usr/local/share/hspell/

#include <stdio.h>
#include "hspell.h"
#include "linginfo.h"

int main()
{
  char* test_data[] = { "שולחן", "אשה", "נשות", "ילדינו"};
  const int test_data_count = 4;

  // init
  struct dict_radix *dict;  // opaque pointer for hspell's dict
  if(hspell_init(&dict, HSPELL_OPT_LINGUISTICS) != 0)
    return -1;
  
  // get stems
  int i;
  for(i = 0; i < test_data_count; i++)
  {
    // check test_data[i]
    char *desc, *stem;
    printf("stem for %s -- ", test_data[i]);
    if(linginfo_lookup(test_data[i],&desc,&stem))
    {
      puts("found -- \n");
      // loop through possible stems
      int stem_num;
      for (stem_num=0; ;stem_num++) {
        char buf[80];
        if (!linginfo_desc2text(buf, desc, stem_num)) break; // ran out of stems
        //if (linginfo_desc2ps(desc, stem_num) & prefspec) 
          printf("\t%s(%s%s)\n", linginfo_stem2text(stem, stem_num), buf, "");
      }
    }
    else
      puts("not found!\n");
  }

  // cleanup
  hspell_uninit(dict);
  return 0;
}
