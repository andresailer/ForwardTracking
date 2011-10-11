#ifndef Crit2_ChangeRZRatio_h
#define Crit2_ChangeRZRatio_h

#include "ICriterion.h"


namespace FTrack{
   
   /** Criterion: ...
    */
   class Crit3_ChangeRZRatio : public ICriterion{
      
      
      
   public:
      
      Crit3_ChangeRZRatio ( double maxChange );
      
      virtual bool areCompatible( Segment* parent , Segment* child );
      
      virtual ~Crit3_ChangeRZRatio(){};
      
      
   private:
      
      double _ratioChangeMaxSquared;

      
      
   };
   
}













#endif
