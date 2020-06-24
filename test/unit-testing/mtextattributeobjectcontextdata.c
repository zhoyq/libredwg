// TODO DEBUGGING
#define DWG_TYPE DWG_TYPE_MTEXTATTRIBUTEOBJECTCONTEXTDATA
#include "common.c"

void
api_process (dwg_object *obj)
{
  int error, isnew;
  BITCODE_BS class_version; /*!< r2010+ =3 */
  BITCODE_B is_default;
  BITCODE_B in_dwg;
  BITCODE_H scale;
  BITCODE_BS flag;
  BITCODE_BD rotation;
  BITCODE_2RD insertion_pt;
  BITCODE_2RD alignment_pt;
  // MTEXTATTR
  BITCODE_B enable_context;
  struct _dwg_object *context;

  Dwg_Version_Type dwg_version = obj->parent->header.version;
#ifdef DEBUG_CLASSES
  dwg_obj_mtextattributeobjectcontextdata *_obj = dwg_object_to_MTEXTATTRIBUTEOBJECTCONTEXTDATA (obj);

  CHK_ENTITY_TYPE (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, class_version, BS);
  CHK_ENTITY_TYPE (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, is_default, B);
  CHK_ENTITY_TYPE (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, in_dwg, B);
  CHK_ENTITY_H (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, scale);

  CHK_ENTITY_2RD (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, insertion_pt);
  CHK_ENTITY_2RD (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, alignment_pt);
  CHK_ENTITY_TYPE (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, rotation, BD);
  CHK_ENTITY_TYPE (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, flag, BS);

  CHK_ENTITY_TYPE (_obj, MTEXTATTRIBUTEOBJECTCONTEXTDATA, enable_context, B);
  if (!dwg_dynapi_entity_value (_obj, "MTEXTATTRIBUTEOBJECTCONTEXTDATA", "mtext", &context, NULL))
    fail ("MTEXTATTRIBUTEOBJECTCONTEXTDATA.context");
  else if (context)
    {
      if (context->fixedtype != DWG_TYPE_MTEXTOBJECTCONTEXTDATA)
        fail ("Wrong MTEXTATTRIBUTEOBJECTCONTEXTDATA.context.fixedtype %s %d != MTEXTOBJECTCONTEXTDATA",
              dwg_type_name (context->fixedtype), context->fixedtype);
    }
#endif
}
