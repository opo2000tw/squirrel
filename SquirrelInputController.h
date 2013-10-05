
#import <Cocoa/Cocoa.h>
#import <InputMethodKit/InputMethodKit.h>
#import <rime_api.h>

@interface SquirrelInputController : IMKInputController {
  id                          _currentClient;         // the current active client
  NSString                   *_preeditString;         // the cached preedit string
  NSRange                     _selRange;
  NSUInteger                  _caretPos;
  NSArray                    *_candidates;
  NSUInteger                  _lastModifier;
  NSEventType                 _lastEventType;
  RimeSessionId               _session;
  NSString                   *_schemaId;
  // for chord-typing
  char _chord[128];
  NSTimer *_chordTimer;
}

-(void)commitString:(NSString*)string;
-(void)showPreeditString:(NSString*)string
                selRange:(NSRange)range
                caretPos:(NSUInteger)pos;
-(void)showCandidates:(NSArray*)candidates
          andComments:(NSArray*)comments
           withLabels:(NSString*)labels
          highlighted:(NSUInteger)index;

-(BOOL)processKey:(int)rime_keycode modifiers:(int)rime_modifiers;

-(void)onChordTimer:(NSTimer *)timer;
-(void)updateChord:(int)ch;
-(void)clearChord;

@end
